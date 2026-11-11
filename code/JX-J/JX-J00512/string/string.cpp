#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string a;
	char b;
	long long n,x,cnt=0,ans=0;
	cin>>n;
	while(n--){
        cin>>x>>b;
        for(long long i=cnt;i<cnt+x;i++){
            a[i]=b;
        }
        cnt+=x+1;
	}
	cnt--;
	for(long long i=0;i<cnt/2-1;i++){
        if(a[i]!=a[cnt-1-i]){
            ans++;
        }
	}
	cout<<ans;
	return 0;
}
