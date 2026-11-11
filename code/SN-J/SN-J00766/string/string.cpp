//姓名：霍梓颐 考号：SN-J00766 学校：西北大学附属中学 
#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char c;
}y[200005];
long long j,an;
char ac;
int n;
long long ans;
int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	j=1;
	for(int i=1;i<=n;i++){
		cin>>an>>ac;
		if(y[j].c!=ac){
			j++;
			y[j].c=ac;
		}
		y[j].num+=an;
	}
	int i=1;
	while(i!=j){
		long long minn=min(y[i].num,y[j].num);
		long long imin=0;
		if(y[i].num<=y[j].num) imin=i;
		else imin=j;
		if(y[i].c!=y[j].c) ans+=minn;
		y[i].num-=y[imin].num;
		y[j].num-=y[imin].num;
		if(imin==i) i++;
		else j--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
