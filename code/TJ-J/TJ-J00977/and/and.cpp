#include<bits/stdc++.h>
using namespace std;
//priority_queue<int>a;
//vector<int>s;
const int N=2e5+5;
int n,m,c,ans,l,z,s[N],qi,yi;
//bool cmp(int l,int r){
//	return l>r;
//}
int a[N][40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l;
		a[i][0]=l;
		c=0;
		while(l!=0){
			c++;
		if(l/2*2!=l)a[i][c]=1;
		l/=2;
		a[i][35]++;
		}
		z=max(z,a[i][35]);
	}
	//cout<<z;
	for(int i=z;i>=1;i--){
		c=0;
		for(int j=1;j<=n;j++){
			//cout<<1;
			if(a[j][i]){
				c++;
				s[c]=j;
				//cout<<1;
			}
		}
		if(c>=m){qi=i-1,l=c;break;}
	}
	if(qi==0){cout<<0;return 0;}
	//sort(c+1,c+1+n,cmp);
		for(int j=1;j<=l;j++){
			//cout<<a[s[j]][0]<<" ";
		}
		//cout<<z<<" ";
	for(int i=qi;i>=1;i--){
		z=yi;
		for(int j=1;j<=l;j++){
			if(a[s[j]][i]&&s[j]){
				z++;
				//cout<<z<<" ";
			}
		}
		if(z<=m){
			for(int j=1;j<=l;j++){
			if(a[s[j]][i]&&s[j]){
				yi++;
				if(!ans)ans=a[s[j]][0];
				else ans&=(a[s[j]][0]);
				//cout<<a[s[j]][0]<<" ";
				s[j]=0;
			}
			}
		}
		if(z>m){
			for(int j=1;j<=l;j++){
			if(!a[s[j]][i]&&s[j]){
				s[j]=0;
			}
			}
		}
		if(yi==m)break;
	}
	//cout<<yi<<" ";
	for(int j=1;j<=l;j++){
		if(s[j]&&yi<m){
			yi++;
			if(!ans)ans=a[s[j]][0];
			else ans&=(a[s[j]][0]);
			//cout<<a[s[j]][0]<<" ";
			s[j]=0;
		}
		if(yi==m)break;
	}
	cout<<ans;
	return 0;
}
