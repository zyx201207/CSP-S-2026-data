#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,st,ed;
struct node{
	ll num;char x;
}p[200010];
ll ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
    	cout<<0;
    	return 0;
	}
	if(n==2){
		int a,b;char x,y;
		cin>>a>>x>>b>>y;
		if(x==y)cout<<0;
		else cout<<min(a,b);
		return 0;
	}
    st=1,ed=n;
    for(int i=1;i<=n;i++){
    	cin>>p[i].num>>p[i].x;
	}
	for(int i=1,j=n;i<j;i++,j--){
		if(p[i].x==p[j].x&&p[i].num==p[j].num){
			st++,ed--;
		}
		else{
			if(p[i].x==p[j].x){
				p[i].num=abs(p[i].num-p[j].num);
				ed--;
			}
			break;
		}
	}
	if(st==ed){
		return 0;
	}
	for(int i=st,j=ed;i<j;){
		if(p[i].x==p[j].x){
			if(p[i].num>p[j].num){
				p[i].num-=p[j].num;
				j--;
			}
			else{
				p[j].num-=p[i].num;
				i++;
			}
		}
		else{
			ans+=min(p[i].num,p[j].num);
			if(p[i].num>p[j].num){
				p[i].num-=p[j].num;
				j--;
			}
			else if(p[i].num<p[j].num){
				p[j].num-=p[i].num;
				i++;
			}
			else{
				i++,j--;
			}
		}
	}
	cout<<ans;
    return 0;
}
