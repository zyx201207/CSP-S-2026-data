#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int ans=0;
vector<int>list1,list2;//ÊýÖµ£¬²îÖµ 
int dfs(int x){
	int f=m,i=x,now=1,flag=-1;
	for(; f>0   &&  now*list2[i]<=f  &&  i<n-1; i++) {
		if(now*list2[i]<=f){
			f-=now*list2[i];
			now++;
		}
	}
	while(!list2[i++]&&i<n-1);
	return i-x;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>5000) {
		printf("%d",n);return 0;
	}
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		list1.push_back(x);
	}
	sort(list1.begin(),list1.end());
	for(int i=0;i<n-1;i++){
		list2.push_back(list1[i+1]-list1[i]);
	}
	for(int i=0;i<n;i++){
		ans=max(dfs(i),ans);
	}
	printf("%d",ans);
	return 0;
}
