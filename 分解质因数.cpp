#include<bits/stdc++.h>
using namespace std;

int a[110];

int main()
{
    int T,n;
    cin>>T;
    for (int i=1;i<=T;i++) cin>>a[i];
    for (int i=1;i<=T;i++)
    {
        n=a[i];
        for (int j=2;j*j<=a[i];j++)
        {
            if (a[i]%j==0)
            {
                cout<<j<<" ";
                while (a[i]%j==0)
                {
                    a[i]/=j;
                }
            }
        }
        if (n%a[i]==0 && a[i]!=1) cout<<a[i];
        cout<<endl;
    }

    return 0;
}