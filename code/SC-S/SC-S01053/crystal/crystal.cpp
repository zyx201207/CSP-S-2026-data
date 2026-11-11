#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	int a[500000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int s=1;
	for(int y=0;y<n;y++){
			if(a[y] == a[y+1]){
				s+=1;
			}	
		}
	if(m != 0){
		for(int j=1;j<n;j++){
			for(int x=j-1;x>=0;x--){
				int chn=a[j]-a[x];
				m=m-chn;
				if(m <= 0){
					break;
				}else{
					s+=1;
				}
			}
		}
	}
	cout<<s;
	return 0;
}