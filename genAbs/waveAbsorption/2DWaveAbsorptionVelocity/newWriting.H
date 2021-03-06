    os.writeKeyword("absorptionDir") << absorptionDir_ << 
        token::END_STATEMENT << nl;
    os.writeKeyword("nPaddles") << nPaddles_ << token::END_STATEMENT << nl;

    writeEntry(os, "initialWaterDepths", initialWaterDepths_);
    writeEntry(os, "meanAngles", meanAngles_);
    writeEntry(os, "zSpanL", zSpanL_);

    #if OFVERSION >= 1712
        os.writeEntryIfDifferent<vector>("uCurrent", vector::zero, uCurrent_);
        os.writeEntryIfDifferent<label>("nEdgeMin", 0, nEdgeMin_);
        os.writeEntryIfDifferent<label>("nEdgeMax", 0, nEdgeMax_);
    #else
        writeEntryIfDifferent<vector>(os, "uCurrent", vector::zero, uCurrent_);
        writeEntryIfDifferent<label>(os, "nEdgeMin", 0, nEdgeMin_);
        writeEntryIfDifferent<label>(os, "nEdgeMax", 0, nEdgeMax_);
    #endif

    os.writeKeyword("allCheck") << allCheck_ << token::END_STATEMENT << nl;

    writeEntry(os, "value", *this);