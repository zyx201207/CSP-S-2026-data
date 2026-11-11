#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m;
struct node{
	string s;
	int k;
};
bool cmp(node x,node y){
	return x.s>y.s;
}
string opp(int x,int y){
	bitset<32>bx(x);
	bitset<32>by(y);
	string r,s1=bx.to_string(),s2=by.to_string();
	int res=0;
	for(int i=0;i<32;i++){
		if(s1[i]=='1'&&s2[i]=='1')r+='1';
		else if(s1[i]=='1'&&s2[i]=='0')r+='0';
		else r+='0';
	}
	return r; 
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n<=20){
		int ans=0;
		for(int i=0;i<(1<<n);i++){
			int sum=INT_MAX;
			bitset<32>b(i);
			if(b.count()!=m)continue;
			string s=b.to_string();
			reverse(s.begin(),s.end());
			for(int j=0;j<n;j++)if(s[j]=='1')sum&=a[j];
			ans=max(ans,sum);
		}
		cout<<ans;
	}
	else{
		if(m==1)cout<<*max_element(a,a+n);
		else if(m==2){
			int ans=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
		}
		else if(m==n){
			int ans=a[0];
			for(int i=1;i<n;i++)ans&=a[i];
			cout<<ans;
		}
		else if(m==n-1){
			int len,n1,Max=INT_MAX,ans=0;
			node x[n];
			for(int i=0;i<n;i++)Max&=a[i];
			for(int i=0;i<n;i++)x[i].s=opp(a[i],Max),x[i].k=i;
			sort(x,x+n,cmp);
			for(int j=0;j<x[0].s.size();j++){
				len++;
				if(x[0].s[j]==1)break;
			}
			for(int i=0;i<n;i++){
				int len1=0;
				for(int j=0;j<x[i].s.size();j++){
					len1++;
					if(x[i].s[j]==1)break;
				}
				if(len>len1)break;
				n1++;
			}
			for(int i=0;i<n1;i++){
				int sum=INT_MAX;
				for(int j=0;j<n;j++)if(j!=x[i].k)sum&=a[j];
				ans=max(ans,sum);
			}
			cout<<ans;
		}
		else{
			sort(a,a+n,greater<int>());
			int ans=a[0];
			for(int i=0;i<m;i++)ans&=a[i];
			cout<<ans;
		}
	}
	return 0;
}
//骗分万岁,骗85+啥实力 
