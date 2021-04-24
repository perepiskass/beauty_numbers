
#pragma once

constexpr size_t my_pow(size_t x, size_t n)
{
    return n > 0 ? x*my_pow(x, n-1): 1;
}

template<size_t BASE, size_t DIGIT>
struct beauty
{
    static_assert(BASE > 1 &&  DIGIT > 1, "Template parameters must be greater than 1");

    constexpr size_t get_count() const
    {
        size_t result = 0;

        size_t mass[(BASE-1) *  (DIGIT/2) + 1] = {0};
        size_t number = 0;

        while(!mass[(BASE-1) *  (DIGIT/2)])
        {
            mass[sum(number++)]++;
        }

        size_t multiplier = 1;
        if constexpr (DIGIT%2)
            multiplier = BASE;

        for(size_t i = 0; i < (BASE-1) *  (DIGIT/2) + 1; ++i)
        {
            result += my_pow(mass[i], 2) * multiplier;
        }
        return result;
    }
private:
    constexpr size_t beauty::sum(size_t num) const
    {
        size_t sum = 0;

        while(num / BASE)
        {
            sum += num % BASE;
            num /= BASE;
        }
        sum += num;

        return sum;
    }
};
