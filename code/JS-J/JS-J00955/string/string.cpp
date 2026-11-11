#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt=0;
string s;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long a;
        char b;
        cin>>a;
        cin>>b;
        for(long long j=1;j<=a;j++){
            s[j+cnt]=b;
        }
        cnt+=a;
    }
    for(long long i=1;i<=cnt/2+cnt%2;i++){
		if(s[i]!=s[cnt-i]){
			s[cnt-i]=s[i];
			ans++;
		}
	}
	cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
