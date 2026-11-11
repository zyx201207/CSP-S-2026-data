//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;
//										int score=400;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
//										int score=400;
//										int score=400;
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],c_a[500005],c_m,ans,q,a_ans;
bool t=1;
bool cmp(int x,int y){
	return abs(x)<abs(y);
}
void solve(){//20-30¡¯ 
	for(int i=0;i<n;i++){
		c_m=m;
		ans=0;
		for(int j=0;j<n;j++){
			c_a[j]=a[j]-a[i];
		}sort(c_a,c_a+n,cmp);
//		for(int j=0;j<n;j++){
//			cout<<c_a[j];
//		}
//		cout<<endl;
		for(int j=0;j<n;j++){
			if(c_m>=abs(c_a[j])){
				ans++;
//				cout<<j<<" "<<c_a[j]<<"  "<<"\t";
				c_m-=abs(c_a[j]);
			}else break;
			
		}a_ans=max(ans,a_ans);
//		cout<<"\t\t"<<ans<<endl;
	}cout<<a_ans;
}
void solve_AB(){  //30¡¯
	int mid=0;
	int q=a[1]-a[0];
	for(int r=mid;r<n;r++){
		if(q<=m){
			ans++;
			m-=q;
//			cout<<r<<" "<<m<<'\t';
		}else{
			break;
		}
	}cout<<ans+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}q=a[1]-a[0];
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]!=q){
			t=0;
		}
	}if(t)solve_AB();
	else solve();
	return 0;
}
