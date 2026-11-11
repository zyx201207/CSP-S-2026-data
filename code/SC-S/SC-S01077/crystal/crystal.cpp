#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5+5;
__int128 n,m,a[maxn];
__int128 pre[maxn];
long long cnt,ans;

__int128 d[maxn],sumd,sum[maxn];

void read(__int128 &x){
	x=0;
	string s;cin>>s;
	int len=s.length();
	int jud=0;
	if(s[0]=='-'){
		jud=1;
	}
	for(int i=jud;i<len;i++){
		__int128 idx=s[i]-'0';
		x=x*10;x+=idx;
	}
	if(jud) x=0-x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		//cout<<pre[i]<<" ";
	}//cout<<'\n';
	
	int tar=0;//上一个删除的位置 
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		sumd+=(cnt*d[i]);
		
		cnt++;
		//cout<<a[i]<<" "<<sumd<<" "<<cnt<<'\n';
		
		if(sumd>m){
			ans=max(ans,cnt-1);
			
			int interval=1;
			while(sumd-interval*a[i]+(pre[tar+interval]-pre[tar])>m){
				//cout<<sumd-interval*a[i]+(pre[tar+interval]-pre[tar])<<'\n';
				interval++;
			} 
			sumd=sumd-interval*a[i]+(pre[tar+interval]-pre[tar]);
			cnt-=(interval);tar+=interval;
			//cout<<a[i]<<" "<<sumd<<" "<<cnt<<'\n';
		}
	}
	//cout<<cnt<<'\n';
	ans=max(ans,cnt);
	cout<<ans;
	return 0;
}