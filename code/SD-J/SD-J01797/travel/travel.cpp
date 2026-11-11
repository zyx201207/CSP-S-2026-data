#include <bits/stdc++.h> 
using namespace std;
string s,c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long i,cnt = 0,sum = 0;
	cin>>c1>>s1>>c2>>s2;
	for(i = 0;i <= 3;i ++) s[i] = '0';
	for(i = 0;i <= 1;i ++){
		if(c1[i] == c2[i]) cnt++;
		if(s1[i] == s2[i]) sum++;
	}
	if(cnt == 2){
		s[0] = '1';
		if(sum == 2){
			s[1] = '1';
			if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')){
				s[2] = '1';
				if((s1[2] == 'A' && s2[2] == 'B') || (s2[2] == 'A' && s1[2] == 'B') || (s2[2] == 'C' && s1[2] == 'B') || (s2[2] == 'B' && s1[2] == 'C')){
					s[3] = '1';
				}
				else s[3] = '0';
			}
			else{
			 	if((s1[2] == 'D' && s2[2] == 'F') || (s2[2] == 'D' && s1[2] == 'F')){
					s[2] = '1';
					s[3] = '1';
				}
				else{
					s[2] = '0';
					s[3] = '0';
				}
			}
		} 
		else s = "1000";
	} 
	else s = "0000";
	for(i = 0;i <= 3;i ++) cout<<s[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
