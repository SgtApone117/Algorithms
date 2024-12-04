void fillLPSTable(string& pattern, int& size, vector<int>& lps)
{
    int length = 0;
    int i = 1;
    while(i < size)
    {
        if(pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if(length != 0)
            {
                length = lps[length-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string& text, string& pattern)
{
    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m, 0);
    fillLPSTable(pattern,m,lps);

    int i,j;
    i = 0, j = 0;
    while(i < n)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if(j == m)
        {
            cout << "Pattern found at index " << i-j << endl;
            j = lps[j-1];
        }
        else if(text[i] != pattern[j])
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
}