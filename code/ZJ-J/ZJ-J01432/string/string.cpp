#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int number;
	char characters;
}s[200005];
long long ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		int num;
		char c;
		cin>>num>>c;
		s[i].number = num;
		s[i].characters = c;
	}
	int l = 0,r = 0;//Ê£ÓàÖµ 
	int ll = 1,rr = n;//Ö¸Õë 
	while(ll <= rr){
		if(ll == rr){
			break;
		}
		if(s[ll].characters == s[rr].characters){
			ans += abs(s[ll].number - s[rr].number)-l-r;
//			cout<<abs(s[ll].number - s[rr].number)-l-r<<endl;
		}
		else{
			ans += s[ll].number - l <= s[rr].number - r ? s[ll].number - l : s[rr].number - r;
//			cout<<(s[ll].number - l <= s[rr].number - r ? s[ll].number - l : s[rr].number - r)<<endl;
		}
		if(s[ll].number - l < s[rr].number - r){
			r = s[rr].number-r-s[ll].number+l;
			l = 0;
			ll++;
		}
		else if(s[ll].number - l > s[rr].number - r){
			l = s[ll].number-l-s[rr].number+r;
			r = 0;
			rr--;
		}
		else{
			l = 0;
			r = 0;
			ll++;
			rr--;
		}
	}
	cout<<ans;
	return 0;
}
