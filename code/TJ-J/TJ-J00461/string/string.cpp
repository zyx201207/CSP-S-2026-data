#include <bits/stdc++.h>
using namespace std;
char S[11000000000];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long count = 0;
    int n = 0;
    long long len = 0;
    long long length = 0;
    char c ;
    int step = 0;
    cin>>n;
    for(int i = 0;i<n;i++){
    	cin>>len>>c;
    	length += len;
    	for(long long j = step;j<(len+step);j++){
    		S[j] = c;
		}
		step+=len;
	}
	for(long long m=0;m<length/2+1;m++){
		if(!(S[m]==S[length-m])){
			count++;
		}
	}
	cout<<count;
	return 0;
} 
