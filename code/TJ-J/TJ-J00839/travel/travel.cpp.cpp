#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i,j,k;
	string c1,c2,s1,s2,x,y;
	string a[6] = {"A","B","C","D","E"},b[19] = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18"},ans[5] = {"0","0","0","0"};
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		ans[0] = "1";
	}
	else{
		cout << "0000";
		return 0;
	}
	for(i = 0;i <= 17;i++){
		for(j = 0;j <= 4;j++){
			x = b[i] + a[j];
			if(s1 == x){
				for(k = 0;k <= 4;k++){
					y = b[i] + a[k];
					if(s2 == y){
						ans[1] = "1";
						break;
					}
				}
				if(ans[1] == "0"){
					break;
				}
				else{
					if(j <= 2 && k <= 2){
						ans[2] = "1";
						if(j == 0 && k == 1){
							ans[3] = "1";
						}
						else if(j == 1 && (k == 0 || k == 2)){
							ans[3] = "1";
						}
						else if(j == 2 && k == 1){
							ans[3] = "1";
						}
					}
					else if(j > 2 && k > 2){
						ans[2] = "1";
						if(j == 3 && k == 4){
							ans[3] = "1";
						}
						else if(j == 4 && k == 3){
							ans[3] = "1";
						}
					}
				}
			}
		}
	}
	cout << ans[0] + ans[1] + ans[2] + ans[3];
	return 0;
}
