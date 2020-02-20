#include "utilities.h"
#include "std_lib_facilities.h"
#include "masterVisual.h"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    cout << "v0: " << v0;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << v0 << endl;
}

void testVectorSorting(){
    vector<int> percentages;
    int len=10;
    randomizeVector(percentages, len); //Bruker push_back til å legge inn tilfeldige tall
    for (int i=0; i<len; i++){
        cout << percentages[i] << " -- "; //Printer ut verdiene
    }
    cout << endl << medianOfVector(percentages) << endl; //Printer medianen
    swapNumbers(percentages[0], percentages[1]); //Swapper to første verdiene
    sortVector(percentages); //Sorterer hele vectoren, printes ut neste linje
    for (int i=0; i<len; i++){
        cout << percentages[i] << " -- ";
    }
    cout << endl << medianOfVector(percentages) << endl; //Printer ut medianen
}

void testString(){
    int gradeLen{8};
    string grades = randomizeString(gradeLen, 'A', 'F');
    for (int i=0; i<gradeLen; i++){
        cout << grades[i] << endl;
    }

    vector<int> gradeCount;
    int tot=0;
    for (int i=0; i<6; i++){
        char grade = 'A'+i;
        int num=countChar(grades, grade);
        gradeCount.push_back(num);
        cout << grade << ": " << num << "Bidrag: " << num*(5-i) << endl;
        tot+=(num*(5-i));
    }
    double avg = tot/static_cast<double>(gradeLen);
    cout << "Totalt: " << tot << endl << "Snitt: " << avg;
}

void playMastermind(){
    constexpr int size = 4;
    constexpr int letters = 6;
    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
    int lives = 10;
    char upper=('A' + letters - 1);
    string code = randomizeString(size, 'A', upper);
    //string guess = readInputToString(size, 'A', upper);
    string guess = mwin.getInput(size, 'A', upper);
    cout << guess;
    int correct=checkCharactersAndPosition(guess, code);
    int lettersCorrect=checkCharacters(guess, code);
    while (correct<size && lives>0){
        cout << "Beklager, du har ikke gjettet helt riktig! Du gjettet: "
        << guess << " -- hvor " << lettersCorrect << " var antall riktige bokstaver, og "
        << correct << " er paa riktig plass. Riktig er " << code;
        //guess = readInputToString(size, 'A', upper);

        mwin.vr.push_back(new Rectangle{Point{padX,(23-2*lives)*padY},padX,padY});
        mwin.vr[mwin.vr.size()-1].set_fill_color(1);
        mwin.attach(mwin.vr[mwin.vr.size()-1]);


        guess = mwin.getInput(size, 'A', upper);
        correct=checkCharactersAndPosition(guess, code);
        lettersCorrect=checkCharacters(guess, code);
        lives-=1;
    }
    if (lives==0){
        cout << "Beklager, du tapte! Riktig kode var " << code;
    }
    else{
        cout << "Gralla, du vant!!";
    }
    
}