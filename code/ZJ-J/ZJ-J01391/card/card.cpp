#include<bits/stdc++.h>
using namespace std;
int n,m,tail,a[500010],s[500010],lst[300010],ans[300010],ans_first[300010];
vector<int> v[300010];
bool check_a(){
	for(int i=2;i<=n;i++)
		if(a[i]<a[i-1])
			return false;
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(check_a()){
		//ÌØÊâĞÔÖÊa,16`(4/25)
		for(int i=1;i<=n;i++)
			ans[a[i]]=i;
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<' ';
	}
	else if(n<=5000){
		//36`(9/25)
		for(int i=1;i<=n;i++){
			tail=0;
			for(int j=1;j<=m;j++)
				lst[j]=0;
			for(int j=i;j<=n;j++)
				if(lst[a[j]]==0||lst[a[j]]>tail){
					s[++tail]=a[j];
					lst[a[j]]=tail;
				}
				else
					tail=lst[a[j]];
			for(int j=1;j<=m;j++)
				if(lst[j]!=0&&lst[j]<=tail&&s[lst[j]]==j)
					ans[j]++;
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<' ';
	}
	else{
		//60`(15/25)
		for(int i=1;i<=n;i++)
			v[a[i]].push_back(i);
		for(int i=1;i<=n;i++)
			if(lst[a[i]]==0||lst[a[i]]>tail){
				s[++tail]=a[i];
				lst[a[i]]=tail;
			}
			else
				tail=lst[a[i]];
		for(int i=1;i<=m;i++)
			if(lst[i]!=0&&lst[i]<=tail&&s[lst[i]]==i)
				ans_first[i]++;
		for(int i=1;i<=n;i++){
			auto indx=upper_bound(v[a[i]].begin(),v[a[i]].end(),i);
			if(indx!=v[a[i]].end())
				for(int j=i;j<=*indx;j++)
					ans[a[j]]++;
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]+ans_first[i]*v[i][0]<<' ';
	}
	return 0;
}
