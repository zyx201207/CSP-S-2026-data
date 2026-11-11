#include<bits/stdc++.h>
using namespace std;
int ans1,ans2,ans_2,ans3,ans_3,ans4,ans_4,ans5,ans_5;
bool cmp(int a,int b){
	if(a>b){
		return 1;
	}
	else{
		return 0;
	}
}
int n,a[5000005],m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ans1=a[1];
	ans2=a[2];
	ans3=a[3];
	ans4=a[4];
	ans5=a[5];
	for(int i=2;i<=m;i++){
		ans1=ans1&a[i];
	}
	for(int i=2;i<=m;i++){
		ans2=ans2&a[i];
		ans_2=max(ans_2,ans2);
	}
	for(int i=2;i<=m;i++){
		ans3=ans3&a[i];
		ans_3=max(ans_3,ans3);
	}
	for(int i=2;i<=m;i++){
		ans4=ans4&a[i];
		ans_4=max(ans_4,ans4);
	}
	for(int i=2;i<=m;i++){
		ans5=ans5&a[i];
		ans_5=max(ans_5,ans5);
	}

	cout<<max({ans1,ans2,ans3,ans4,ans5});
	return 0;
}
