#include<bits/stdc++.h>
using namespace std;
int n,m;
int cunt=0,num=0,p=0,cnt=0,q=0;
int a[100000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		q+=a[i];
		cunt++;
	}
	sort(a,a+n);
	num=q/cunt;
	for(int i=0;i<n;i++){
		if(a[i]<=num){
			p=num-a[i];
			if(m-p<0){
				break;
			}else{
				m-=p;
				cnt++;
			}
		}else{
			p=a[i]-num;
			if(m-p<0){
				break;
			}else{
				m-=p;
				cnt++;
			}
		}	
	}

	cout<<cnt;
	return 0;
} 
