#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel1.in.txt","r",stdin);
	freopen("travel1.out.txt","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	cout<<1;
	else
	cout<<0;
	if(a==c and b=="01A" and (d=="01B" or d=="01C" or d=="01D" or d=="01F") or b=="01B" and (d=="01A" or d=="01C" or d=="01D" or d=="01F") or b=="01C" and (d=="01B" or d=="01A" or d=="01D" or d=="01F") or b=="01D" and (d=="01B" or d=="01A" or d=="01C" or d=="01F") or b=="01F" and (d=="01B" or d=="01A" or d=="01D" or d=="01C") or b=="02A" and (d=="02B" or d=="02C" or d=="02D" or d=="02F") or b=="02B" and (d=="02A" or d=="02C" or d=="02D" or d=="02F") or b=="02C" and (d=="02B" or d=="02A" or d=="02D" or d=="02F") or b=="02D" and (d=="02B" or d=="02A" or d=="02C" or d=="02F") or b=="02F" and (d=="02B" or d=="02A" or d=="02D" or d=="02C") or b=="03A" and (d=="03B" or d=="03C" or d=="03D" or d=="03F") or b=="03B" and (d=="03A" or d=="03C" or d=="03D" or d=="03F") or b=="03C" and (d=="03B" or d=="03A" or d=="03D" or d=="03F") or b=="03D" and (d=="03B" or d=="03A" or d=="03C" or d=="03F") or b=="03F" and (d=="03B" or d=="03A" or d=="03D" or d=="03C") or b=="04A" and (d=="04B" or d=="04C" or d=="04D" or d=="04F") or b=="04B" and (d=="04A" or d=="04C" or d=="04D" or d=="04F") or b=="04C" and (d=="04B" or d=="04A" or d=="04D" or d=="04F") or b=="04D" and (d=="04B" or d=="04A" or d=="04C" or d=="04F") or b=="04F" and (d=="04B" or d=="04A" or d=="04D" or d=="04C") or b=="05A" and (d=="05B" or d=="05C" or d=="05D" or d=="05F") or b=="05B" and (d=="05A" or d=="05C" or d=="05D" or d=="05F") or b=="05C" and (d=="05B" or d=="05A" or d=="05D" or d=="05F") or b=="05D" and (d=="05B" or d=="05A" or d=="05C" or d=="05F") or b=="05F" and (d=="05B" or d=="05A" or d=="05D" or d=="05C"))
	cout<<1;
	else
	cout<<0;
	if(a==c and b=="01A" and (d=="01B" or d=="01C") or b=="01B" and (d=="01A" or d=="01C") or b=="01C" and (d=="01B" or d=="01A") or b=="01D" and d=="01F" or b=="01F" and d=="01D" or b=="02A" and (d=="02B" or d=="02C") or b=="02B" and (d=="02A" or d=="02C") or b=="02C" and (d=="02B" or d=="02A") or b=="02D" and d=="02F" or b=="02F" and d=="02D" or b=="03A" and (d=="03B" or d=="03C") or b=="03B" and (d=="03A" or d=="03C") or b=="03C" and (d=="03B" or d=="03A") or b=="03D" and d=="03F" or b=="03F" and d=="03D" or b=="04A" and (d=="04B" or d=="04C") or b=="04B" and (d=="04A" or d=="04C") or b=="04C" and (d=="04B" or d=="04A") or b=="04D" and d=="04F" or b=="04F" and d=="04D" or b=="05A" and (d=="05B" or d=="05C") or b=="05B" and (d=="05A" or d=="05C") or b=="05C" and (d=="05B" or d=="05A") or b=="05D" and d=="05F" or b=="05F" and d=="05D")
	cout<<1;
	else
	cout<<0;
	if(a==c and (b=="01A" and d=="01B" or b=="01B" and d=="01C" or b=="01D" and d=="01F") or (b=="02A" and d=="02B" or b=="02B" and d=="02C" or b=="02D" and d=="02F") or (b=="03A" and d=="03B" or b=="03B" and d=="03C" or b=="03D" and d=="03F") or (b=="04A" and d=="04B" or b=="04B" and d=="04C" or b=="04D" and d=="04F") or (b=="05A" and d=="05B" or b=="05B" and d=="05C" or b=="05D" and d=="05F"))
	cout<<1;
	else
	cout<<0;
	return 0;
} 
