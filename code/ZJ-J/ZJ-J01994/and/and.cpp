#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
const int maxn=2e7+39;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,m;
long long num[maxn];
int ans;
int main(int argc, char** argv) {
	freopen("and.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(num[i]>num[j]){
    			int tmp=num[i];
    			num[i]=num[j];
    			num[j]=tmp;
			}
		}
	}
	ans=num[1];
	for(int i=2;i<=m;i++){
		ans=ans&num[i];
	}
	cout<<ans;
	freopen("and.out","w",stdout);
	return 0;
}