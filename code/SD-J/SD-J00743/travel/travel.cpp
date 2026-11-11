  #include <bits/stdc++.h>
  using namespace std;
  int main(){
  	freopen("travel.in", "r", stdin); 
  	freopen("travel.out ", "w", stdout);
  	string xz,xb, yb ,yz;
  	cin >> xz >> xb >> yz >> yb;
  	if(xz == yz){
  		cout << "1";
  		if(xb[0] == yb[0] && xb[1] == yb[1]){
  			cout << "1";
  			if(xb[2] < 'D' && yb[2] < 'D'||xb[2] >= 'D' && yb[2] >= 'D'){
  				cout << "1";
  				if(xb[2] - 1 == yb[2] || xb[2] + 1 == yb[2]){
  					cout << "1";
				  } else {
				  	cout << "0";
				  }
			  } else{
			  	cout << "00";
			  }
	    } else {
		  	cout << "000";
		}
	  } else {
	  	cout << "0000";
	  }
  	return 0;
  }
