#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,k,sum=1;
struct _{
	int a,ans;
}s[N];
bool cmp(_ a,_ b){
	return a.ans<b.ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
		int o=s[i].a;
		while(o){
			s[i].ans+=o*2;
			o/=2;
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=n;i>=1;i--){
		if(k){
			if(i==n)sum=s[i].a;
			else sum&=s[i].a;
			k--; 
		}else break;
	}
	cout<<sum;
}

