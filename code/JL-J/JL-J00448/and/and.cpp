#include<bits/stdc++.h>
using namespace std;
int a[200001];
int b[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int num;
	if(m==1){
		num=-1;
		for(int i=0;i<n;i++){
			num=max(num,a[i]);
		}
		cout<<num;
		return 0;
	}
	if(m==n){
		num=a[0];
		for(int i=0;i<n;i++){
			num=num^a[i];
		}
		cout<<num;
		return 0;
	}
	if(m==2){
		num=-1;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				num=max(num,a[i]^a[j]);
			}
		}
		cout<<num;
		return 0;
	}
    fclose(stdin);
    fclose(stdout);

    return 0;
}
