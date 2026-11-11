#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long all = 0,n = 0,nn = 0,temp1 = 0,nd1 = 0,nd2 = 0;char temp2 = 0,ci;vector <char> string,temp;
	cin>>n;
	for(long long i = 0;i < n;i++){
		cin>>temp1>>temp2;
		all+=temp1;
		for(long long n_i = temp1;n_i > 0;n_i--){
			string.push_back(temp2);
		}

	}
	
	
	if(all % 2 == 0 ) nn = all / 2;
	else nn = (all - 1) / 2;
	for(long long i = nn;i > 0;i--){
		temp.push_back(string[i - 1]);
	}
	
	
	//fenchulai
	for(long long i = nn;i > 0;i--){
		if(temp[i] == temp[nn - i])  nd1 == nd1;
		else nd1++;
	}
	for(long long i = 0;i < n;i++){
		if(string[nn + i + 1] == temp[all - i - 1]) nd1 == nd1;
		else nd1++;
	}
	
	//zhengti
	for(long long i = 0;i < nn;i++){
		if(string[i] != string[all - i + 1]) nd2++;
	} 
		
	if(nd1 > nd2) cout<<nd2;
	else cout<<nd1;
	return 0;
}
