#include <iostream>

uint8_t add(uint8_t x1, uint8_t x2)
{
    return (x1 ^ x2);
}

uint8_t multiply(uint8_t x1, uint8_t x2, uint8_t modul)
{
    uint16_t res = 0;

    for (int i = 0; i < 8; i++)
    {
        if ((x2 >> i) & 1)
        {
            res = res ^ (x1 << i);
        }
    }

    for (int j = 14; j >= 8; j--)
    {
        if ((res >> j) & 1)
        {
            res = res ^ ((256 + modul) << (j - 8));
        }
    }
    uint8_t res2 = res;
    return res2;
}

uint8_t inverse(uint8_t x, uint8_t modul)
{
    uint8_t res = 1;
    int pow_x = 256 - 2;

    for (int i = 7; i >= 0; i--)
    {
        if ((pow_x >> i) & 1)
        {
            res = multiply(res, x, modul);
        }
        if (i != 0)
            res = multiply(res, res, modul);
    }
    return res;
}

int main()
{
    int ch = -1, a1, b1, mod = 27;
    uint8_t a, b; 
    

    while (ch != 0)
    {
        std::cout << "choose:\n1. + \n2. * \n3. a^(-1) \n0. exit \n";
        std::cin >> ch;

        switch (ch)
        {
        case 0:
            break;
        case 1:
            std::cout << "a = ";
            std::cin >> a1;
            if ((a1 > 255) || (a1 < 0))
            {
                std::cout << "a - must be (0,255)\n";
                break;
            }
            std::cout << "b = ";
            std::cin >> b1;
            if ((b1 > 255) || (b1 < 0))
            {
                std::cout << "b - must be (0,255)\n";
                break;
            }
            std::cout << "a + b = " << (int)add(a1, b1) << std::endl;
            break;
        case 2:
            std::cout << "a = ";
            std::cin >> a1;
            if ((a1 > 255) || (a1 < 0))
            {
                std::cout << "a - must be (0,255)\n";
                break;
            }
            std::cout << "b = ";
            std::cin >> b1;
            if ((b1 > 255) || (b1 < 0))
            {
                std::cout << "b - must be (0,255)\n";
                break;
            }
            //std::cout << "modul = ";
            //std::cin >> mod;
            std::cout << "a * b = " << (int)multiply(a1, b1, mod) << std::endl;
            break;
        case 3:
            std::cout << "x = ";
            std::cin >> a1;
            if ((a1 > 255) || (a1 < 0))
            {
                std::cout << "a - must be (0,255)\n";
                break;
            }
            else if (a1 == 0)
            {
                std::cout << "a^(-1) = " << a1 << std::endl;
                break;
            }
            //std::cout << "modul = ";
            //std::cin >> mod;
            std::cout << "a^(-1) = " << (int)inverse(a1, mod) << std::endl;
            break;
        default:
            std::cout << "Invalid input\n";
            break;
        }
        std::cout << std::endl;
    }
}
