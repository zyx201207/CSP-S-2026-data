#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
const int maxn=2e6+8;
int n;
struct stringing{
	int num;
	char s;
	int vis;
}a[maxn];
int ans;
int main(){
	freopen("string.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
	}
	for(int i=1,j=n;i<=n;){
		if(i>=j||a[j].vis==1){
			break;
		}
		if(a[i].s==a[j].s){
			if(a[i].num>a[j].num){
				a[i].num-=a[j].num;
				a[j].vis=1;
				j--;
			}else if(a[i].num==a[j].num){
				a[j].vis=1;
				j--;
			}else{
				a[j].num-=a[i].num;
				i++;
			}
		}else{
			if(a[i].num>a[j].num){
				ans+=a[j].num;
				a[i].num-=a[j].num;
				a[j].vis=1;
				j--;
			}else if(a[i].num==a[j].num){
				ans+=a[j].num;
				a[j].vis=1;
				j--;
			}else{
				ans+=a[i].num;
				a[j].num-=a[i].num;
				i++;
			}
		}
	}
	cout<<ans;
	freopen("travel.out","w",stdout);
	return 0;
}