using System;
using System.IO;

namespace prog2
{
    public class Logger : IDisposable
    {
        public enum severity
        {
            trace,
            debug,
            information,
            warning,
            error,
            critical
        }

        private StreamWriter logw;

        public Logger(string filename)
        {
            logw = new StreamWriter(filename);
        }

        public void Log(string message, severity mes_sev)
        {
            logw.WriteLine($"[{DateTime.Now:G}] [{mes_sev}]: {message}");
        }

        public void Dispose()
        {
            logw.Dispose();
            GC.SuppressFinalize(this);
        }

        ~Logger()
        {
            logw.Dispose();
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            using (var logfile = new Logger(Path.Combine(Environment.CurrentDirectory, "logger.txt")))
            {
                //Console.WriteLine($"{Environment.CurrentDirectory}");
                logfile.Log("1 mes_file", Logger.severity.debug);
                logfile.Log("2 mes_file", Logger.severity.error);
                logfile.Log("3 mes_file", Logger.severity.information);
                logfile.Log("4 mes_file", Logger.severity.debug);
                Console.WriteLine("logfile successful");
            }
        }
    }
}
