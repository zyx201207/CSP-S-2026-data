#include<bits/stdc++.h>
using namespace std;
struct {
	int num;
	char c;
}a[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	for(int i=1,j=n;i<j;){
		if(a[i].num==0&&a[j].num==0){
			break;
		}
		if(a[i].num==0){
			i++;
		}
		if(a[j].num==0){
			j--;
		}
		if(a[i].c!=a[j].c){
			cnt++;
		}
		a[i].num--,a[j].num--;
	}
	cout<<cnt;
	return 0;
}
