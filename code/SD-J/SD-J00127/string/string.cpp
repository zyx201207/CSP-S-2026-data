#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
char y;
vector<long long> a(1);
vector<char> c(1);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t1;
	char t2;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(i==1||y!=t2){
			a.push_back(x);
			c.push_back(y); 
			t1=a.size()-1;
			t2=y;
		}else{
			if(i!=1&&y==t2)a[t1]+=x;
		}
	}
//	for(int i=0;i<a.size();i++)cout<<a[i]<<' '<<c[i]<<'\n';
	//льеп 
	if(a.size()-1==1){
		cout<<0<<'\n';
		return 0;
	}
	if(a.size()-1==2){
		cout<<min(a[1],a[2])<<'\n';
		return 0;
	}
	n=a.size()-1;
	int p=1;
	bool q = 1;
	for(int i=p;i<=n/2;){
		q=1;
		if(n==2){
			if(c[i]!=c[n-i+1])
				ans+=min(a[i],a[n-1+1]);
			break;
		}
		if(a[i]<a[n-i+1]){
			a[n-i]+=a[n-i+1]-a[i];
			if(c[i]!=c[n-i+1])ans+=a[n-i+1];
			else ans+=a[n-i+1]-a[i];
			a[n-i+1]=a[i];
		}else if(a[i]>a[n-i+1]){
			int l=i,r=n-i+1;
			while(l+1!=r&&n>0&&l!=r){
				c[r-1]=c[r];
				a[r-1]+=a[r];
				n--;
				r--;
				q=0;
				p=i;
				if(a[r]>=a[l])break;
			}
		}else if(a[i]==a[n-i+1]&&c[i]!=c[n-i+1]){
			a[n-i+1]=c[i];
			ans+=a[i];
		}
		if(q)p++;
	}
	cout<<ans<<'\n';
	return 0;
}
