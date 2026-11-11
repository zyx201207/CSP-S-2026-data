#include<bits/stdc++.h>
using namespace std;
char s[100000001],ss[100000001];
long long n,m,sum=0,cnt=0,l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s[++cnt]=c;
        }
    }
    long long p=cnt;
    for(int i=1;i<=cnt;i++,p--){
		ss[i]=s[p];
	}
	for(int i=1;i<=(cnt+1)/2;i++)
	{
		if(ss[i]!=s[i])sum++;
	}
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
