#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],c[200005];
struct node{
	int x,y;
}b[10005];
bool cmp(node x1,node y1){
	return x1.x>y1.x;
}
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
//	3
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int a1=a[i];
		string s="";
		while(a1){
			s+=(a1%2)+'0';
			a1/=2;
		}
//		cout<<s<<endl;
		for(int j=0;j<s.size();j++){
			if(s[j]=='1'){
				cnt++;
			}
		}
		b[i].x=cnt,b[i].y=a[i];
		cnt=0;
	}
	sort(b+1,b+n+1,cmp);
	sort(a+1,a+n+1);
	int maxn=-1;
	for(int i=1;i<n;i++){
		c[a[i]]++;
		maxn=max(maxn,a[i]);
	}
	for(int i=maxn;i>=1;i--){
		if(c[i]>=m){
			cout<<i;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
//		cout<<b[i].x<<" "<<b[i].y<<endl;
	}
//	cout<<c[12]<<" ";
	int ans=b[1].y;
//	cout<<b[1].y<<" ";
	for(int i=2;i<=m;i++){
		ans&=b[i].y;
//		cout<<b[i].y<<" ";
	}
	cout<<ans;
	return 0;
} 
