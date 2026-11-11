#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N = 2*10e5+50;
int q_su[N];
char q_ch[N];
int i=0,j;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans = 0;
	j=n;
	cin>>n;
	for(int k=1;k<=n;k++){
		cin>>q_su[k]>>q_ch[k];
	}
	j=n;
	while(i<j){
		if(q_ch[i]==q_ch[j]){
			if(q_su[i]>q_su[j]){
				q_su[i]=q_su[i]-q_su[j];
				j--;
			}else if(q_su[i]<q_su[j]){
				q_su[j]=q_su[j]-q_su[i];
				i++;
			}else{
				i++;j--;
			}
		}
		else{
			if(q_su[i]>q_su[j]){
				ans+=q_su[j];
				q_su[i]=q_su[i]-q_su[j];
				j--;
			}else if(q_su[i]<q_su[j]){
				ans+=q_su[i];
				q_su[j]=q_su[j]-q_su[i];
				i++;
			}else{
				ans+=q_su[i];
				i++;j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
