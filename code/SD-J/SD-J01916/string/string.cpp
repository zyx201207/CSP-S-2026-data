#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char c;
}s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].num>>s[i].c;
	}
	int l=1,r=n;
	node ls=s[l],rs=s[r];
	while(l<r){
		if(ls.c==rs.c){
			int minn=min(ls.num,rs.num);
			ls.num-=minn;
			rs.num-=minn;
		}
		else{
			int minn=min(ls.num,rs.num);
			ls.num-=minn;
			rs.num-=minn;
			ans+=minn;
		}
		if(ls.num==0){
			l++;
			if(l==r){
				break;
			}
			else{
				ls=s[l];
			}
		}
		if(rs.num==0){
			r--;
			if(l==r){
				break;
			}
			else{
				rs=s[r];
			}
		}
	}
	cout<<ans;
	return 0;
} 
