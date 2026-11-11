#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long n,m,ans=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1)cout<<"1";
	else if(n%2==0&&m==2)cout<<n<<" "<<n;
	else if(m==1)cout<<n;
	else if(n%2!=0&&m==2)cout<<n<<" "<<0;
return 0;
}
