#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	int a,b;
	vector<string> as,bs;
	cin >> a;
	for (int i = 0;i<3;i++) cin >> as[i];
	cin >> b;
	for (int i = 0;i<3;i++) cin >>bs[i];
	char cnt[4]={0};
	if (a==b) cnt[0] = '1';
	if (as[1] == bs[1]) cnt[1]='1';
	if ((("A"<= as[2]&&as[2]<="C")&&("A"<=bs[2]&&bs[2]<="C"))||(("D"<=as[2]&&as[2]<="F")&&("D"<=bs[2]&&bs[2]<="F"))) cnt[2] = 1;
	if (as[2]-bs[2] ==1 ||bs[2]==as[2]+1) cnt[3] == '1';
	for (int i = 0;i<4;i++){
		if (cnt[0] == 0){
			cout<<"0000";
		}
		else cout<<cnt[i];
	}
}