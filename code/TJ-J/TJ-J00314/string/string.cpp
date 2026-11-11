#include <bits/stdc++.h>
using namespace std;

#define LL unsigned long long

LL n,len = 0,q[200005];
struct str{
	LL x;
	char c;
}s[200005],s1[200005];

int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
    
    cin>>n;
	for(LL i = 1;i <= n;i++){
		cin>>s[i].x>>s[i].c;
		len += s[i].x;
		s1[n - i + 1].x = s[i].x;
		s1[n - i + 1].c = s[i].c;
		q[i] = q[i - 1] + s[i].x;
	}
	LL last_j = 1,sum = 0;
	for(LL i = 1;i <= n;i++){
		for(LL j = last_j;j <= n;j++){
			if(s1[j].x == s[j].x){
				if(s1[j].c != s[j].c){
					sum += s[i].x;
				}
				last_j++;
				break;
			}
			else if(s1[j].x > s[j].x){
				if(s1[j].c != s[j].c){
					sum += s1[j].x;
				}
				s1[j].x -= s[i].x;
				break;
			}
			else{
				if(s1[j].c != s[j].c){
					sum += s[j].x;
				}
				last_j++;
				s[i].x -= s[j].x;
			}
		}
	}
	cout<<sum / 2;

    return 0;
}
