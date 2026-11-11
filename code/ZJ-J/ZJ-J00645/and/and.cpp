#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
struct point{
	int num;
	string s;
}b[200010];
int maxlen;
void check(int x,int y){
	int len=0;
	while(x){
		len++;
		int p=x%2;
		if(p==1){
			b[y-1].num++;
			b[y-1].s+='1';
		}
		if(p==0){
			b[y-1].s+='0';
		}
		x/=2;
	}
	maxlen=max(maxlen,len);
}
bool cmp(point x,point y){
	return x.num>y.num||x.num==y.num&&x.s<y.s;
}
int res[200010];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		check(a[i],i);
	}
	sort(a+1,a+1+n);
	for(int i=0;i<n;i++){
		if(b[i].s.size()<maxlen){
			for(int j=b[i].s.size();j<maxlen;j++){
				b[i].s+='0';
			}
		}	
	}
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);	
			}
		}
		cout<<ans;
		return 0;
	}
	sort(b,b+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<b[i].s.size();j++){
			res[i]+=pow(2,j)*(b[i].s[j]-'0');
		}
	}
	ans=res[1];
	for(int i=2;i<=m-1;i++){
		ans&=res[i];
	}
	cout<<ans;
	return 0;
}