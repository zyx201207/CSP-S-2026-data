#include <bits/stdc++.h>
using namespace std;
string ans;
string c1,s1,c2,s2;
string l1,l2;
char seat1,seat2;
int main(){
        freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
        
        cin>>c1>>s1>>c2>>s2;
        if (c1 == c2){
			ans += "1";
		} 
		else{
			cout<<"0000";
			return 0;
		}
		
		l1 = s1[0] + s1[1];
		l2 = s2[0] + s2[1];
		
		seat1 = s1[2];
		seat2 = s2[2];
		if (l1 != l2){
			cout<<"1000";
			ans = "1000";
			return 0;
		}  
		else if (l1 == l2){
			ans += "1";
			if ((seat1 == 'A' || seat1 == 'B' || seat1 == 'C') && (seat2 == 'A' || seat2 == 'B' || seat2 == 'C')){
				ans += "1";
				if ((seat1 == 'A' && seat2 == 'B')||(seat2 == 'A' && seat1 == 'B')){
					ans +="1";
				}
				else if ((seat1 == 'C' && seat2 == 'B')||(seat2 == 'C' && seat1 == 'B')){
					ans +="1";
				}
				
				else{
					ans += "0";
				}
			}
			else if ((seat1 == 'D' || seat1 == 'F') && (seat2 == 'D' || seat2 == 'F')){
				ans += "1";
				if ((seat1 == 'D' && seat2 == 'F')||(seat2 == 'D' && seat1 == 'D')){
					ans += "1";
				}
				else{
					ans += "0";
				}
		}
			else{
				ans += '0';
				ans += '0';
		}
		
		}
		
		
		
		cout<<ans;
		 
		return 0;


}
