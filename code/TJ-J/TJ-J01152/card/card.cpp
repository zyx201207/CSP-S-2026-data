#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],s[n];
	int num=0;
	for(int i=0;i<n;i++){
		s[num]=a[i];
		for(int j=i;j>0;j--){
			if(s[j]==s[i]){
				num=j;
			}else{
				num++;
			}
		}
	}
	return 0;
}
