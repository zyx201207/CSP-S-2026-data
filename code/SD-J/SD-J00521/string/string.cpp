#include<bits/stdc++.h>
using namespace std;
int duan;
long long sum;
struct note{
	int ans;
	char cns;
}str[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>duan;
	for(int i=1;i<=duan;i++){
		cin>>str[i].ans>>str[i].cns;
	}
	for(int i=1,j=duan;i<=j;){
		if(str[i].cns!=str[j].cns){
			sum+=min(str[i].ans,str[j].ans);
		}
		if(str[i].ans>str[j].ans){
			str[i].ans-=str[j].ans;
			j--;
		}
		else if(str[i].ans<str[j].ans){
			str[j].ans-=str[i].ans;
			i++;
		}
		else{
			i++,j--;
		}
	}
	cout<<sum;
	return 0;
} 
