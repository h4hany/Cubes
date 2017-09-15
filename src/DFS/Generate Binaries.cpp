#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int const n = 4, total_ones = 2;
int l = 0, cur[n];
string ans[100000];

void generate_binaries(int indx, int cunt){

	if (cunt == total_ones){
		string num = "";
		for (int i = 0; i < n; i++){
			num += char(cur[i] + 48);
		}
		ans[l++] = num;
		return;
	}

	for (int i = indx; i < n; i++){
		cur[i] = 1;
		generate_binaries(i + 1, cunt + 1);
		cur[i] = 0;
	}
}

void generate_binaries_2(int indx, int cunt){
    
	if (cunt == total_ones){
		for (int i = 0; i < n; i++){
			cout<<cur[i];
		}
		cout<<endl;
		return;
	}
	
	if(indx >= n) return;

	for(int i = 0; i <= 1; i++){
	    cur[indx] = i;
	    generate_binaries_2(indx + 1, ((i == 0)? cunt: cunt + 1));
	    cur[indx] = 0;
	}
}

int main(){

	generate_binaries(0, 0);

	sort(ans, ans + l);

	for (int i = 0; i < l; i++){
		cout << ans[i] << endl;
	}
	
	// another solution (blind dfs)
	generate_binaries_2(0, 0);

	return 0;
}
