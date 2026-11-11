#include<bits/stdc++.h>
#define int long long
#define go(x)(cout<<x<<'\n',void())
#define go1(x)(cout<<x<<' ',void())
#define vi vector<int>
#define in(x)(cin>>x,void())
#define in1(x,y)(cin>>x>>y,void())
#define in2(x,y,z)(cin>>x>>y>>z,void())
#define pb push_back
#define vc vector<char>
using namespace std;
const int MAXN=1048581;
int t[MAXN];
string dt[MAXN];
bool cmp(string a,string b){
	return stol(a)>stol(b);
}
bool cmp1(int a,int b){
	return a>b;
}
string zh(int a){
	string b;
	while(a>0){
		if(dt[a]!=""){
			b+=dt[a];
			return b; 
		}
		b+=to_string(a%2);
		a/=2;
		dt[a]=b;
	} 
	return b; 
}
string fanzhuan(string a){
	string b;
	for(int i=a.size()-1;i>=0;i--) b+=a[i];
	return b;
}
void solve(){
	int n,m;
	in1(n,m);
	int a[n+1];
	string b[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	if(m==1){
		sort(a,a+n,cmp1);
		go(a[0]);
		return ; 
	}
	for(int i=0;i<n;i++) b[i]=zh(a[i]);
	sort(b,b+n,cmp);//´Ó´óÍùÐ¡ÅÅ 
	if(m==n){
		string ans;
		for(int i=0;i<n-1;i++){
			for(int j=min(b[i].size(),b[i+1].size());j>=0;j--){
			 	if(b[i][j]==1 && b[i+1][j]==b[i][j]) ans+='1';
			 	else ans+='0';
			} 
			b[i]=fanzhuan(ans);
		}
		go(b[n-1]);
		return ;
	}
	if(m==2){
		long maa=-1;
		string ans;
		for(int i=0;i<n-1;i++){
			for(int k=i+1;k<n;k++){
				for(int j=min(b[i].size(),b[k].size());j>=0;j--){
			 		if(b[i][j]==1 && b[i+1][j]==b[i][j]) ans+='1';
			 		else ans+='0';
				} 
				b[i]=fanzhuan(ans);
				maa=max(maa,stol(b[i]));
			}
		}
		go(maa);
		return ;
	}
	string ans;
	for(int i=0;i<n-1;i++){
		for(int k=i+1;k<n;k++){
			for(int j=min(b[i].size(),b[k].size());j>=0;j--){
			 	if(b[i][j]==1 && b[i+1][j]==b[i][j]) ans+='1';
			 	else ans+='0';
			} 
			b[i]=fanzhuan(ans);
			maa=max(maa,stol(b[i]));
		}
	}
	return ;

}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	while(t--) solve();
	return 0;
}

