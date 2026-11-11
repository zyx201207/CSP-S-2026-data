#include<iostream>
#include<cmath>
using namespace std;
const int N=2e5+1000;
int n;
int num[N];
long long cnt=0;
char zi[N];
long long gs=0; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>zi[i];
		gs+=num[i];
	}
	int l=1,r=n;
	if(gs%2==0){
		while(l<r){
			if(zi[l]==zi[r]){
				if(num[l]==num[r]){
					l++;
					r--;
				}
				else if(num[l]>num[r]){
					num[l]=num[l]-num[r];
			 		r--;
				}
				else if(num[l]<num[r]){
					num[r]=num[r]-num[l];
					l++;
				}
			}
			else if(zi[l]!=zi[r]){
				if(num[l]>num[r]){
					cnt=cnt+num[r];
					num[l]=num[l]-num[r];
					r--;
				}
				else if(num[l]<num[r]){
					cnt=cnt+num[l];
					num[r]=num[r]-num[l];
					l++;
				}
				else if(num[l]==num[r]){
					cnt=cnt+num[l];
					l++;
					r--;
				}
			}
		}
	} 
	else{
		while(l<=r){
			if(zi[l]==zi[r]){
				if(num[l]==num[r]){
					l++;
					r--;
				}
				else if(num[l]>num[r]){
					num[l]=num[l]-num[r];
			 		r--;
				}
				else if(num[l]<num[r]){
					num[r]=num[r]-num[l];
					l++;
				}
			}
			else if(zi[l]!=zi[r]){
				if(num[l]>num[r]){
					cnt=cnt+(num[r]);
					num[l]=num[l]-num[r];
					r--;
				}
				else if(num[l]<num[r]){
					cnt=cnt+(num[l]);
					num[r]=num[r]-num[l];
					l++;
				}
				else if(num[l]==num[r]){
					cnt=cnt+num[l];
					l++;
					r--;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
