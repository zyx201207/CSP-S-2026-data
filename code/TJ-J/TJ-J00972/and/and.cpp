#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[200001];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	long long sum,num;
	if(m==1){
		num=-1;
		for(int i=0;i<n;i++){
			num=max(num,a[i]);
		}
	}
	else if(m==n){
		num=a[0];
		for(int i=1;i<n;i++){
			num=num&a[i];
		}
	}
	else if(m==2){
		num=-1;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				num=max(num,a[i]&a[j]);
			}
		}
	}
	else if(m==n-1){
		num=-1;
		for(int i=0;i<n;i++){
			if(i==0){
				sum=a[1];
			}
			else{
				sum=a[0];
			}
			for(int j=1;j<n;j++){
				if(j!=i){
					sum=sum&a[j];
				}
			}
			num=max(num,sum);
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
