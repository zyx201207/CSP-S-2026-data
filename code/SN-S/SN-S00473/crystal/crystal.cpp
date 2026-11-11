//准考证号：SN-S00473 姓名：铁瀚青 学校：陕西延安中学 
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long ma=0,a[n+3]={};
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		long long c=m,s=1;
		for(int j=1;j<=n-i;j++){
			if(a[i]-a[i+j]>c)break;
			else{
				c-=a[i]-a[j+i];
				s++;
			}
		}ma=max(ma,s);
	}cout<<ma;
}
