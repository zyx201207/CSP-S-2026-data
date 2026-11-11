#include<bits/stdc++.h>
using namespace std;

int a,b,pa,pb,wa,wb,ans1,ans2,ans3,ans4;
char w;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> pa >> w;
	wa = w-'A'+1;
	cin >> b >> pb >> w;
	wb = w-'A'+1;
//	cout << wa << " " << wb;
	if(a==b){
		ans1 = 1;
		if(pa==pb){
			ans2 = 1;
			if((wa<=3&&wb<=3)||(wa>3&&wb>3)){
				ans3 = 1;
				if(wa<wb){
					swap(wa,wb);
				}
				if(wa-wb==1||(wa==6&&wb==4)){
					ans4 = 1;
				}
			}
		}
	}
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}
