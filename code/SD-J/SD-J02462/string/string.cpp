#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
#define LL long long
LL cnt=0;
struct Node{
	LL x;
	string y;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	LL n;
	cin>>n;
	int top=0;
	for(int i=1;i<=n;i++){
		LL co;
		string so;
		cin>>co>>so;
		if(so==a[top].y){
			a[top].x+=co;
		}else{
			a[++top].x=co;
			a[top].y=so;
		}
	}
	for(int i=1,j=top;i<j;){
		if(a[i].y==a[j].y){
			if(a[i].x<a[j].x){
				i++;
				a[j].x-=a[i].x;
			}else if(a[i].x==a[j].x){
				i++;
				j--;
			}else{
				j--;
				a[i].x-=a[j].x;
			}
		}
		else{
			if(a[i].x<a[j].x){
				cnt+=a[i].x;
				a[j].x-=a[i].x;
				i++;
			}else if(a[i].x==a[j].x){
				cnt+=a[i].x;
				i++;
				j--;
			}else{
				cnt+=a[j].x;
				a[i].x-=a[j].x;
				j--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
//ÇóAC 
