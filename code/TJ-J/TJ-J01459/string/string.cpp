#include<bits/stdc++.h>
using namespace std;
int sum=0,num[200005],n;
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>ch[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(ch[l]!=ch[r]){
			if(num[l]>num[r]){
				sum+=num[l]-num[r];
				num[l]-=num[r];
				r--;
			}else if(num[r]<num[l]){
				sum+=num[r]-num[l];
				num[r]-=num[l];
				l++;
			}else{
				sum+=num[r];
				l++,r--;
			}
		}else{
			if(num[l]>num[r]){
				num[l]-=num[r];
				r--;
			}else if(num[r]<num[l]){
				num[r]-=num[l];
				l++;
			}else{
				l++,r--;
			}
		}
	}
	cout<<sum;
	return 0;
} 
