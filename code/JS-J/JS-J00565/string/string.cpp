#include <bits/stdc++.h>
 
using namespace std;
 char c[1000000010],v[1000000010];

int main(){
    long long  n,cnt=0,ans=0;

   
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char b;
        cin>>a>>b;
        
        for (long long j = 0; j < a; j++)
        {
            c[cnt]=b;
            cnt++;
        }
        
    }
    for (long long i = cnt-1; i >=(cnt-1)/2-1 ; i--)
    {
        v[cnt-1-i]=c[i];
    }

    for (long long i = 0; i <=(cnt-1)/2; i++)
    {
        int x=v[i];
        int y=c[i];
        if(x!=y) ans++;
    }
    cout<<ans;
	fclose(stdin);
    fclose(stdout);
	return 0;
   
}
