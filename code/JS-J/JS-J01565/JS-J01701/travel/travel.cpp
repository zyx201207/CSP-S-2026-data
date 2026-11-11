#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream fin("travel.in");
    ofstream fout("travel.out");

    string a,b;
    long long c,d;
    fin >> c >> a;
    fin >> d >> b;

    if(c != d){
        fout<<"0000";
    }else if(a[0] != b[0] || a[1] != b[1]){
        fout <<"1000";
    }else if((a[2] == 'A' && (b[2] != 'B' && b[2] != 'C')) || (a[2] == 'B' && (b[2] != 'A' && b[2] != 'C')) || (a[2] == 'C' && (b[2] != 'B' && b[2] != 'A'))){
        fout <<"1100";
    }else if((a[2] == 'D' && b[2] != 'F') || (a[2] == 'F' && b[2] != 'D')){
        fout <<"1100";
    }else if((a[2] == 'A' && b[2] == 'C') || (a[2] == 'C' && b[2] == 'A')){
        fout<<"1110";
    }else{
        fout<<"1111";
        //fout << a[2]<<b[2];
    }


    fin.close();
    fout.close();
    return 0;
}