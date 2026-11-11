#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	long long l=1,r=n,lk=a[1],rk=0;
	long long ans=0;
	//分别表示左边位置、右边位置、左边剩余、右边剩余
	while(l<r){
		if(c[l]==c[r]){//如果双方一样 
			if(lk==0){//如果右边有剩余
				if(rk==a[l]){
					rk=0;
					r++;
					l--;
				} 
				if(rk>=a[l]){//如果右边够 
					rk-=a[l];
					l++;
				}
				else{
					lk=a[l]-rk;
					rk=0;
					r--;
				}
			}
			else if(rk==0){//左边有剩余 
				if(lk==a[r]){
					lk=0;
					l++;
					r--;
				}
				if(lk>a[r]){
					lk-=a[r];
					r--;
				}
				else{
					rk=a[r]-lk;
					lk=0;
					l++;
				}
			}
			else{
				if(lk>=rk){
					lk-=rk;
					rk=0;
					r--;
				}
				else{
					rk-=lk;
					lk=0;
					l++;
				}
			}
			continue;
		}
		if(lk==0)//左边无剩余，需要增加 
			lk+=a[l];
		if(rk==0)//右边无剩余，需要增加 
			rk+=a[r];
		if(lk==rk){
			ans+=rk;
			rk=0;
			lk=0;
			l++;
			r--;
		}
		else if(lk>rk){
			ans+=rk;
			lk-=rk;
			rk=0;
			r--;
		}
		else{
			ans+=lk;
			rk-=lk;
			lk=0;
			l++;
		}
	} 
	cout<<ans;
	return 0;
}
