#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int l,n;
long long m;
long long a[N];
long long s[N];
char str[N];


vector<char>l_str;vector<long long>l_nt;
vector<char>r_str;vector<long long>r_nt;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>l;
	for(int i=1;i<=l;i++){
		cin>>a[i]>>str[i];
		m+=a[i];
		s[i]=s[i-1]+a[i];
	}
	long long mid=m/2;
	for(int i=1;i<=l;i++){
		if(s[i]<=mid){
			l_str.push_back(str[i]);
			l_nt.push_back(a[i]);
		}else if(s[i-1]<=mid&&s[i]>mid){
			if(mid-s[i-1]){
				l_str.push_back(str[i]);
				l_nt.push_back(mid-s[i-1]);
			}
			if(s[i]-mid-(m%2)){
				r_str.push_back(str[i]);
				r_nt.push_back(s[i]-mid-(m%2));
			}
		}else{
			r_str.push_back(str[i]);
			r_nt.push_back(a[i]);
		}
	}
	int l_size=l_str.size();
	int r_size=r_str.size();
	int l=0,r=r_size-1;
	long long sum=0;
	
	while(l<=l_size&&r>=0){
		if(l_str[l]==r_str[r]){
			if(l_nt[l]>r_nt[r]){
				l_nt[l]-=r_nt[r--];
			}else if(l_nt[l]<r_nt[r]){
				r_nt[r]-=l_nt[l++];
			}else{
				r--;l++;
			}
		}else{
			if(l_nt[l]>r_nt[r]){
				sum+=r_nt[r];
				l_nt[l]-=r_nt[r--];
			}else if(l_nt[l]<r_nt[r]){
				sum+=l_nt[l];
				r_nt[r]-=l_nt[l++];
			}else{
				sum+=l_nt[l];
				r--;l++;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
} 


