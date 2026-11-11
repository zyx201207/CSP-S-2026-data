//wanghaoyu xidianzhongxue SN-J00636
#include<bits/stdc++.h>
using namespace std;
long long n,m,len,sum;
string s;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
    	cin>>m>>c;
    	len+=m;
    	for(int i=0;i<m;i++){
    		s+=c;
		}
	}
	for(int l=0;l<=len/2-1;l++){
		for(int r=len-l-1;r>=len-l-1;r--){
			if(s[l]!=s[r])sum++;
		}
	}
	cout<<sum;
    return 0;
}
