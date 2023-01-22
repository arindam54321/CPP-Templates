vector<int> isprime(1e7 + 5, 1); // prime or not?
vector<int> prime; // all prime numbers
vector<int> spf(1e7 + 5); // smallest prime factor

void isPrimeSeive(int n) {
    isprime[0] = isprime[1] = 0;

    for (int i = 2; i < n; i = i + 1) {
        if (isprime[i] == 1) {
            prime.emplace_back(i);
            spf[i] = i;
        }

        for (int j = 0; j < prime.size() && i * prime[j] < n && prime[j] <= spf[i]; j = j + 1) {
            isprime[i * prime[j]] = 0;
            spf[i * prime[j]] = prime[j];
        }
    }
}
