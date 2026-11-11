#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,sl=0;
	cin>>n>>m;
	long long a[n+5],b[n+5]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sl++;
	}
	int i=1;
	while(n--){
		int num=0;
		bool key=0;
		for(int j=i;j<=n;j++){
			if(sl<1) continue;
			if(key==1) break;
			if(a[j]!=-1) b[a[j]]++;
			if(b[a[j]]>1){
				for(int s=a[j];s<=j;s++){
					a[j]=-1;
					sl--;
					key=1;
				}
			}
			num++;
		}
		i++;
		cout<<num<<" ";
	}
	cout<<endl;
	return 0;
}
