#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	int n[a];
	char m[a];
	int sum=0;
	for(int i=0;i<a;i++){
		cin>>n[i]>>m[i];
		sum+=n[i];
	}
	int ans=a-1;
	int u=sum;
	if(sum%2==1) sum=sum/2+1;
	else sum/=2;
	for(int i=0;i<a;i++){
		if(sum<=0){
			ans=i;
			break;
		} 
		sum-=n[i];
		
	}
	int i=0,j=a-1;
	int i_=n[i],j_=n[j];
	int ans_=0;
	while(1){
		if(i==ans or j==ans){
			if(u%2==0){
				if(m[i]!=m[j]){
					ans_+=i_;
				} 
				break;
			} 
			else{
				if(i==ans){
					i_--;
					if(m[i]!=m[j]) ans_+=i_;
				}
				else if(j==ans){
					j_--;
					if(m[i]!=m[j]) ans_+=i_;
				}
				break;
			}
		}
		else if(i_>j_){
			if(m[i]!=m[j]){
				ans_+=j_;
				
			}
			i_-=j_;
			j--;
			j_=n[j];
		}
		else if(i_<j_){
			if(m[i]!=m[j]){
				ans_+=i_;
			}
			j_-=i_;
			i++;
			i_=n[i];
		}
		else if(i_==j_){
			if(m[i]!=m[j]){
				ans_+=j_;
			}
			i++; 
			j--;
			j_=n[j];
			i_=n[i];
		}
	}
	cout<<ans_;
	return 0;
} 
