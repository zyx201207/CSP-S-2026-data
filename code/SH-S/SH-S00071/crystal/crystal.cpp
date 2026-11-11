#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m;
ll a[N];
int ans,cnt;

void A(){
	int q=1,p=1;
	while(m>=q&&q<=(n-1)){
		m-=q;
		q++;
		p++;
	}
	cout<<p<<"\n";
}
void B(){
	ll gap=a[2]-a[1];
	ll q=gap;
	int p=1;
	while(m>=q&&p<=(n-1)){
		m-=q;
		q+=gap;
		p++;
	}
	cout<<p<<"\n";
}
int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0); 
	cin>>n>>m;
	bool flag1=false;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=i)	flag1=true;
	}	
	if(!flag1){
		A();
		return 0;
	}

	sort(a+1,a+n+1);
	ll gap=a[2]-a[1];
	bool flag2=false;
	for(int i=2;i<=n;++i){
		if(gap!=a[i]-a[i-1]){
			flag2=true;
			break;
		}
	}
	if(!flag2){
		B();
		return 0;
	}

	ll tot,val;
	int cur;
	ans=1;
	for(int i=2;i<=n;++i){

		tot=m;
		val=a[i];
		cur=i-1;
		cnt=1;
		while(tot&&cur>=1){

			if(tot>=(val-a[cur])){
				tot-=(val-a[cur]);
				cnt++;
				cur--;
			}else	break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
	return 0;
}
